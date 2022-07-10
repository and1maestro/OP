﻿/*Програмно cтворити текстовий файл, кожен рядок якого містить інформацію про рахунок клієнта банку : ПІБ клієнта та сума коштів на його рахунку(у форматі 
«12090, 40 грн.»).Дані у файл ввести з клавіатури в процесі роботи програми.Завершити введення даних натисканням комбінації клавіш Ctrl - V.Спроєктувати клас 
Account, атрибутами якого є ПІБ, сума коштів на рахунку(задається полями гривні, копійки).Також спроєктувати клас Список, елементами якого є об'єкти класу 
Account. АТД Список реалізувати на основі зв’язного списку. Класи повинні мати конструктори, методи виведення об’єктів, методи для виконання поставлених завдань,
можливо інші методи. Розробити програму, яка створює масив об'єктів - рахунків, ініціалізуючи їх при створенні даними із текстового файлу.Визначити рахунок, 
який має найменшу суму на своєму рахунку.На основі даного масиву сформувати Список клієнтів, сума коштів яких(на рахунку) перевищує задану величину(задається 
з клавіатури).Додавання елементів у Список здійснювати за допомогою перевантаженого оператора “ += ”, наприклад, список += елемент.Програма повинна забезпечувати
наочне виведення усіх вхідних, вихідних та проміжних даних, а також контроль можливих помилок.Для обробки помилок використати виключні ситуації.*/

#include "Header.h"
#include "Classes.h"

int main()
{
    int s;
    cout << "Enter the amount of people: ";
    cin >> s;
    List L;
    input_file("File.txt", s);
    output_file(L, "File.txt", s);
    cout << endl << "Your list: \n" << endl;
    L.print();
    Account A = smallest(L);
    cout << endl << "The account with the least amount of money: \n" << endl;
    A.print();
    int a;
    cout << endl << "Type in the amount of money: ";
    cin >> a;
    List L1 = Bigger(L, a);
    cout << endl << "Your list: \n" << endl;
    L1.print();
}