#include "address_book.h"
#include <stdio.h>
#include <stdlib.h>

void print_person(const Person * person){
	printf("Name: %s \nAge: %d \nPhone Number: %s\n\n" , person->fullName, person->age, person->phoneNumber);
}

void print_address_book(const Address_book* address_book){
	printf("\n**************\nADDRESS BOOK\n**************\n\n");
	
	for(int i = 0 ; i < address_book->size ; i++){
		print_person(address_book->book + i);
	}
}

Address_book* create_address_book(void){
	Address_book * newBook = malloc(sizeof(Address_book));
	printf("How many people will you input?");
	int peopleCount = 0;
	scanf("%d", &peopleCount);
	newBook->book = (Person *) malloc(sizeof(Person) * peopleCount);
	newBook->size = peopleCount;
	
	for(int i = 0 ; i < peopleCount ; i++){
		printf("Enter Name: ");
		char * newName = (char *) malloc(50);
		scanf("%s" , newName);
		printf("Enter Age: ");
		int newAge = 0;
		scanf("%d" , &newAge);
		printf("Enter Number: ");
		char * number = (char *) malloc(50);
		scanf("%s" , number);
		

		printf("\nCreating entry with name: %s , age: %d, number: %s \n", newName, newAge, number);
		
		Person * currentPerson = newBook->book;
		(currentPerson + i)->fullName = newName;
		(currentPerson + i)->age = newAge;
		(currentPerson + i)->phoneNumber = number;
		
	}
	
	return newBook;
}
