#include <stdio.h>
#include <stdint.h>
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

                                // funciones de impresion 

// impresion encabeazdo 
void print_encabezado(struct Header *header){
    printf("Numero de estudiantes: %u\nNumero de cursos: %u\nNumero de matriculas: %u\n\n",
    header->studentCount , header->courseCount , header->enrollmentCount);
}


// impresion estudiantes
void print_estudiantes(struct Estudiantes *estudiante){

    // Extraer banderas
    uint8_t isFemale = (estudiante->bandera & 0x80) >> 7; // Bit más significativo (F)
    uint8_t isPostgrad = (estudiante->bandera & 0x40) >> 6; // Segundo bit más significativo (G) 
    
    printf("id: %u \nEl nombre del estudiante es: %s\nedad: %u \ngenero: %s\nnivel: %s\n\n", 
        estudiante->ID_Estudiante , estudiante->nombre , estudiante->edad ,
        isFemale? "Femenino" : "Masculino",isPostgrad? "Pregrado" : "Posgrado");
}

// filtro de estudiantes
void filtro_estudiantes(struct Estudiantes *estudiante){

    // Extraer banderas
    uint8_t isFemale = (estudiante->bandera & 0x80) >> 7; // Bit más significativo (F)
    uint8_t isPostgrad = (estudiante->bandera & 0x40) >> 6; // Segundo bit más significativo (G) 
    
    printf("Nombre: %-23s || edad: %u || genero: %s\n", 
        estudiante->nombre , estudiante->edad , isFemale? "Femenino" : "Masculino");
}


                            // main

int main(int argc, char *argv[]) {
                                            // extraccion del documento con fopen
    // Leer parámetros de la línea de comandos
    char *filename = argv[1];
    int menor = atoi(argv[2]);
    int mayor = atoi(argv[3]);

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
                                        
                                        // impresiones

    // impresion del enacabezado
    print_encabezado(&header);

    printf("filtro estudiantes:\n");
    for (int i = 0; i < numEstudiantes; i++){
        
        if(mayor >= estudiante[i].edad && estudiante[i].edad >= menor){
            filtro_estudiantes((&estudiante[i]));    
        }
        
    }
    

    return 0;
}

                                         // NOTA
// Para que este archivo se ejecute desde la consola ingresamos los argumentos de la main al inicio de la misma
// modificando el "filename*" y poniendo este en donde se leera nuestro archivo
// y definiendo el mayor y el menor como argumentos de la funcion que se ingresan desde la consola 

// para correr nos paramos en consola y ejecutamos
// gcc carlos_rivera_tarea1.c -o filtroEstudiantes.out (para crear el archivo ejecutable que puede tener cualquier nombre)
//  ./filtroEstudiantes.out sample_data.bin 20 25 (para dar los 3 argumentos, nombre del archivo , menor y mayor)