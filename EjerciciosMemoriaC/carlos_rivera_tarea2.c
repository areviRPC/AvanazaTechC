#include <stdio.h>
#include <stdint.h>
#include <string.h>
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

// Estructura filtroCursos

struct FiltroCurso {
    uint32_t filtroId;
    char cursoName[32];
    uint32_t sumaEdades;
    uint32_t conteoEstudiantes; 
};

// Estructura del 

                                // funciones de impresion 


// impresion de filtros de cursos
void printfiltro_cursos(struct FiltroCurso *filtroCurso , float promedio ){
    printf(" %-35s - %.1f\n",
    filtroCurso->cursoName , promedio);
}


                            // main

int main(int argc, char *argv[]) {
                                            // extraccion del documento con fopen
    

    char *filename = argv[1];
    
    FILE *file = fopen( filename, "rb");
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


    // relleno el objeto filtroCurso con los nombres de los cursos, el Id y los contadores

    struct FiltroCurso filtroCurso[numCursos];
    
    for (int i = 0; i < numCursos; i++){
        filtroCurso[i].filtroId = curso[i].ID_Curso;
        strcpy(filtroCurso[i].cursoName , curso[i].nombre); 
        filtroCurso[i].conteoEstudiantes = 0;
        filtroCurso[i].sumaEdades = 0;
    }
    

    // Lectura y guarado de matriculas en un array
    struct Matriculas matricula[numMatriculas];
    fread(&matricula , sizeof(struct Matriculas) , numMatriculas , file);
                                        


                                        // funcion para filtro de cursos


    for (int i = 0; i <  numMatriculas; i++){

        for(int j = 0; j < numCursos; j++){

            if (matricula[i].idCursoMatr == filtroCurso[j].filtroId){

                for (int n = 0; n < numEstudiantes; n++){

                    if(matricula[i].IdEstudiante == estudiante[n].ID_Estudiante){
                        
                        filtroCurso[j].sumaEdades += estudiante[n].edad;
                        filtroCurso[j].conteoEstudiantes += 1;

                    }
                }
            }
        }
    }

                                            // impresiones

    // impresion filtro cursos
    for (int x = 0; x < numCursos; x++){
        float promedio = 0;
        if (filtroCurso[x].conteoEstudiantes == 0){
            promedio = 0;
        }else{
            float promedio = (((float) filtroCurso[x].sumaEdades)/((float)(filtroCurso[x].conteoEstudiantes))); 
            printfiltro_cursos(&filtroCurso[x] , promedio);
        }

    }
    
    
    

    return 0;
}

                                         // NOTA
// Para que este archivo se ejecute desde la consola ingresamos los argumentos de la main al inicio de la misma
// modificando el "filename*" y poniendo este en donde se leera nuestro archivo
// y definiendo el mayor y el menor como argumentos de la funcion que se ingresan desde la consola 

// para correr nos paramos en consola y ejecutamos
// gcc carlos_rivera_tarea2.c -o filtroCursos.out (para crear el archivo ejecutable que puede tener cualquier nombre)
//  ./filtroCursos.out sample_data.bin (solo 1 argumento correspondiendote a la cocumentacion)