#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    float grade;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Nu se mai pot adăuga studenți.\n");
        return;
    }
    
    printf("Introdu numele studentului: ");
    getchar(); // Consumă newline-ul anterior
    fgets(students[student_count].name, NAME_LENGTH, stdin);
    students[student_count].name[strcspn(students[student_count].name, "\n")] = '\0'; // Elimină newline-ul
    
    printf("Introdu vârsta studentului: ");
    scanf("%d", &students[student_count].age);
    printf("Introdu nota studentului: ");
    scanf("%f", &students[student_count].grade);
    
    student_count++;
    printf("Student adăugat cu succes!\n");
}

void display_students() {
    if (student_count == 0) {
        printf("Nu există studenți înregistrati.\n");
        return;
    }
    
    printf("\nLista studenților:\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d. %s, %d ani, Nota: %.2f\n", i + 1, students[i].name, students[i].age, students[i].grade);
    }
}

void save_students_to_file() {
    FILE *file = fopen("students.txt", "w");
    if (!file) {
        printf("Eroare la salvarea fișierului.\n");
        return;
    }
    
    for (int i = 0; i < student_count; i++) {
        fprintf(file, "%s %d %.2f\n", students[i].name, students[i].age, students[i].grade);
    }
    
    fclose(file);
    printf("Studenții au fost salvați în fișier.\n");
}

int main() {
    int choice;
    do {
        printf("\n1. Adaugă student\n2. Afișează studenți\n3. Salvează în fișier\n4. Ieșire\n");
        printf("Alege o opțiune: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: add_student(); break;
            case 2: display_students(); break;
            case 3: save_students_to_file(); break;
            case 4: printf("Ieșire...\n"); break;
            default: printf("Opțiune invalidă.\n");
        }
    } while (choice != 4);
    
    return 0;
}