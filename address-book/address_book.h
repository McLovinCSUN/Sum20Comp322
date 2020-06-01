
#ifndef __ADDRESS_BOOK_H__
#define __ADDRESS_BOOK_H__
/* TODO: Add your structures here */ 

typedef struct Person{
	char * fullName;
	int age;
	char * phoneNumber;
}Person;

typedef struct Address_book{
	Person * book;
	int size;
} Address_book;


/* Function declarations. Do not modify! Implement those functions in address_book.c */
void print_person(const Person* person);
void print_address_book(const Address_book* address_book);

Address_book* create_address_book(void);
void destroy_address_book(Address_book* address_book);

#endif /* __ADDRESS_BOOK_H__ */
