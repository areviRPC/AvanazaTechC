#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#pragma pack(push, 1) // Para evitar relleno



// estrcutura para el encabezado
struct Header {
    uint16_t magic;          // Cadena mágica: 2 bytes
    uint32_t studentCount;   // Cantidad de estudiantes: 4 bytes
    uint32_t courseCount;    // Cantidad de cursos: 4 bytes
    uint32_t enrollmentCount;// Cantidad de matrículas: 4 bytes
};

// Estrutura para estudiantes 
struct Estudiantes{
    uint32_t ID_Estudiante;
    uint8_t bandera;
    char nombre[23];
    uint32_t edad;
};

// Estructura para los cursos
struct Cursos {
    uint32_t ID_Curso;
    char nombre[32];
    uint32_t horas;
};

// Estructura para la matricula
struct Matriculas {
    uint32_t IdEstudiante;
    uint32_t idCursoMatr;
    uint32_t año;
    uint32_t Semestre;
};

// estrcutura de filtro de años

struct FiltroAños{
uint32_t añoFiltro;
uint32_t semestreFiltro;
uint32_t mujerPregrado;
uint32_t hombrePregrado;
uint32_t mujerPosgrado;
uint32_t hombrePosgrado;
};


                            // funcoin para extraer los años unicos 


void extraerAnios(struct Matriculas *matriculas, long num_matriculas, uint32_t anios[], int *cantidad_anios) {
    *cantidad_anios = 0;
    
    for (uint32_t i = 0; i < num_matriculas; i++) {
        uint32_t anio_actual = matriculas[i].año;
        int yaExiste = 0;
        // Verifica si el año ya esta en la lista de años únicos
        for (int j = 0; j < *cantidad_anios; j++) {
            if (anio_actual == anios[j]) {
                yaExiste = 1;
                break;
            }
        }
        // Si el año no esta en la lista se agrega
        if (!yaExiste) {
            anios[*cantidad_anios] = anio_actual;
            (*cantidad_anios)++;
        }
    }

}

                            // main

int main(int argc, char *argv[]) {
                                            // extraccion del documento con fopen y lectura por consola
    
    char *filename = argv[1];
    FILE *file = fopen(filename, "rb"); 
    if (!file) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

                                            // lectura del encabezado 


    struct Header header; // creamos el objeto encabezado
    fread(&header, sizeof(struct Header), 1, file);

    // Verificar cadena mágica
    if (header.magic == 0xaaae) {
        printf("Archivo no válido (magic incorrecto)\n");
        fclose(file);
        //return 1;
    }else{
        printf("lectura del magic correcta\n");
    }

    // recasteo de los contadores (por si acaso)

    long numEstudiantes = (long)header.studentCount;
    long numCursos = (long)header.courseCount;
    long numMatriculas = (long)header.enrollmentCount;


                                                // lectura del resto del documento

    // lectura y guardado de todos los estudiantes en un array

    struct Estudiantes estudiante[numEstudiantes];
    fread(&estudiante , sizeof(struct Estudiantes), numEstudiantes ,file);

    // Lectura y guardado de todos los cursos en un array

    struct Cursos curso[numCursos];
    fread(&curso , sizeof(struct Cursos) , numCursos , file);

    // Lectura y guarado de matriculas en un array
    struct Matriculas matricula[numMatriculas];
    fread(&matricula , sizeof(struct Matriculas) , numMatriculas , file);


                                                // creacion de objeto años

    // estrcutrua años



                                                        // CONTADOR DE AÑOS

    uint32_t listaAños[numMatriculas];
    int cantidad_anios;

    extraerAnios(matricula, numMatriculas, listaAños, &cantidad_anios);

 


                                            // creacion de lista de objetos tipo año para leer 


    int tamañoAños = (cantidad_anios*4);
    struct FiltroAños filtroAños[tamañoAños];

    int p = 0;

    for(int a = 0; a < tamañoAños; a++){
        for(int m = 1; m <= 4 ; m++){
            filtroAños[p].añoFiltro = listaAños[a]; 
            filtroAños[p].semestreFiltro = m;
            filtroAños[p].hombrePregrado = 0;
            filtroAños[p].mujerPregrado = 0;
            filtroAños[p].hombrePosgrado = 0;
            filtroAños[p].mujerPosgrado = 0;
            p++;
        }
    }




    int contado = 0;

    for (int i = 0; i < tamañoAños; i++) {
        int YaMatriculados[numEstudiantes];
        int cantidadMatriculados = 0;

        // Inicializamos el arreglo en 0
        for (int m = 0; m < numEstudiantes; m++) {
            YaMatriculados[m] = 0;
        }

        for (int j = 0; j < numMatriculas; j++) {

            if (matricula[j].año == filtroAños[i].añoFiltro &&
                matricula[j].Semestre == filtroAños[i].semestreFiltro) {

                for (int e = 0; e < numEstudiantes; e++) {

                    if (matricula[j].IdEstudiante == estudiante[e].ID_Estudiante) {

                        // Verificamos si ya fue contado
                        int yaContado = 0;
                        for (int y = 0; y < cantidadMatriculados; y++) {
                            if (YaMatriculados[y] == estudiante[e].ID_Estudiante) {
                                yaContado = 1;
                                break;
                            }
                        }

                        if (!yaContado) {
                            // Clasificación por bandera
                            uint8_t isFemale = (estudiante[e].bandera & 0x80) >> 7;
                            uint8_t isPostgrad = (estudiante[e].bandera & 0x40) >> 6;

                            if (isFemale && isPostgrad)
                                filtroAños[i].mujerPosgrado++;
                            else if (isFemale && !isPostgrad)
                                filtroAños[i].mujerPregrado++;
                            else if (!isFemale && isPostgrad)
                                filtroAños[i].hombrePosgrado++;
                            else
                                filtroAños[i].hombrePregrado++;

                            // Agregamos el estudiante al listado de ya contados
                            YaMatriculados[cantidadMatriculados] = estudiante[e].ID_Estudiante;
                            cantidadMatriculados++;
                        }
                    }
                }
            }
        }
    }

                                        // impresiones


    // impresion de años
    printf("año:   | semestre | hombrePreg | mujPreg | hombrePost | mujerPost\n\n");
    for (int i = 0; i < tamañoAños; i++){
        printf("%-10d  %-10d  %-11d  %-11d  %-10d  %-10d\n",
            filtroAños[i].añoFiltro , filtroAños[i].semestreFiltro , filtroAños[i].hombrePregrado , 
            filtroAños[i].mujerPregrado , filtroAños[i].hombrePosgrado , filtroAños[i].mujerPosgrado);
    }

    
    return 0;
}