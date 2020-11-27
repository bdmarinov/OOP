Да се моделира онлайн магазин (Store) за определени продукти (тениски, ризи, маратонки, GSM, лаптопи, автомобилни гуми, и др.). За целта:

•	Изберете продукт, за който ще реализирате магазина и определете характеристиките на продукта (например марка, модел, категория, цвят, размер, операционна система, памет, и др.)

•	Да се дефинира клас Product, който има следните член-данни:

SKU (stock keeping unit) – уникален номер на продукта (задължително);
Brand – марка (задължително); 
Model – модел (задължително); 
Category – категория (ако е приложимо); 
Price – единична цена (задължително); 
Count – брой налични продукта в магазина (задължително); 
Други член данни в зависимост от избрания продукт и определените характеристики.

•	Да се дефинират съответни методи за създаване, четене, запис и промяна на продукти;

•	Да се дефинира клас Store, който съдържа динамичен списък (масив) от продукти в магазина, заедно с техния брой. Да се дефинират съответни методи за:

Добавяне на нов продукт; 
Изтриване на продукт; 
Промяна на продукт; 
Извеждане на екрана на списък с наличните продукти и техния брой; 
Записване на всички продукти във файл; 
Зареждане на продуктите от файл.

•	Да се дефинира главна програма, реализираща следното меню:

A	Add new product; 
X	Delete product; 
C	Change product; 
D	Display products; 
S	Save products; 
L	Load products; 
Q	Quit