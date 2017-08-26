#include <stdio.h>
#include <string.h>

struct Books
{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};

/* 函数声明 */
void printBook(struct Books book);

int main()
{
	struct Books Book1; // 声明Book1，类型为Books
	struct Books Book2; // 声明Book2，类型为Books

	/* Book1 详述 */
	strcpy(Book1.title, "C Programming");
	strcpy(Book1.author, "Nuha Ali");
	strcpy(Book1.subject, "C Programming Tutorial");
	Book1.book_id = 123;
	
	/* Book2 详述 */
	strcpy(Book2.title, "Telecom Billing");
	strcpy(Book2.author, "Zara Ali");
	strcpy(Book2.subject, "Telecom Billig Tutorial");
	Book2.book_id = 456;
	
	/* 输出Book1信息 */
	printBook(Book1);

	/* 输出Book2信息 */
	printBook(Book2);

	return 0;
}

void printBook(struct Books book)
{
	printf("Book title : %s\n", book.title);
	printf("Book author: %s\n", book.author);
	printf("Book subject: %s\n", book.subject);
	printf("Book book_id: %d\n", book.book_id);
}
