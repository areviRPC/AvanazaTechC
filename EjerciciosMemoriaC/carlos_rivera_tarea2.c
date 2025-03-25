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

// impresion de cursos
void print_cursos(struct Cursos *curso){
    printf("idCurso: %u\nNombre del curso: %s\nHoras: %u\n\n",
    curso->ID_Curso , curso->nombre , curso->horas );
}

// impresion de matricula
void print_matricula(struct Matriculas *matricula){
    printf("id Estudiante: %u\nId Curso %u\nAño de matricula: %u\nSemestre: %u\n\n",
    matricula->IdEstudiante , matricula->idCursoMatr , matricula->año , matricula->Semestre);
}

                            // main

int main() {
                                            // extraccion del documento con fopen
    
    FILE *file = fopen("sample_data.bin", "rb");
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

    // impresion de estudiantes 
    for (int i = 0; i < 1; i++){
        print_estudiantes((&estudiante[i]));
    }

    // impresion de crusos
    for (int i = 0; i < 1; i++){
        print_cursos((&curso[i]));
    }

    // impresion matricula
    for (int i = 0; i < 1; i++){
        print_matricula((&matricula[i]));
    }
    

    int mayor;
    int menor;

    printf("ingrese el limite mayor al que desea filtrar: ");
    scanf("%d" , &mayor);
    printf("ingrese el limite menor al que desea filtrar: ");
    scanf("%d" , &menor);

    printf("filtro estudiantes:\n");
    for (int i = 0; i < numEstudiantes; i++){
        
        if(mayor >= estudiante[i].edad && estudiante[i].edad >= menor){
            filtro_estudiantes((&estudiante[i]));    
        }
        
    }
    

    return 0;
}