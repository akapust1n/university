## Описание третьй лабораторной
Лабораторная №1 была полностью переделана в связи с ошибками, допущенными при проектировании.
Без загрузки плагинов лаба ничего не умеет.
После загрузки плагина "Студенты" появляется функционал, присущей первой лабе.

### Как собрать?
При компиляции при помощи Qt Creator - убрать галочку с "Shadow build" (Projects - Build - General - Shadow build).
Запуск через консоль: ``` qmake && make && ./lab3 ```

<img src="https://raw.githubusercontent.com/akapust1n/university/master/ppo/lab3/Screens/myimage.gif" data-canonical-src="https://raw.githubusercontent.com/akapust1n/university/master/ppo/lab3/Screens/myimage.gif" width="410" height="260" />


### Как выглядит интерфейс без загрузки плагинов
![Without plugins](https://raw.githubusercontent.com/akapust1n/university/master/ppo/lab3/Screens/woPlugins.png)

### Загружаем плагин "Студенты"
![With students plugin0](https://raw.githubusercontent.com/akapust1n/university/master/ppo/lab3/Screens/withStudentsPlugin.png)

Появилась возможность осуществлять действия,описываемы в первой лабораторной.
Так же хочется отметить, что имеется возможность изменять цвет отображаемого дерева и его шрифт.

### Загружаем два дополнительных плагина
![With students plugin2](https://raw.githubusercontent.com/akapust1n/university/master/ppo/lab3/Screens/withBasePlugins.png)

Загрузилось два плагина: Экспорт студентов в файл и экспорт выбранного поля(первый столбец поля) в файл. Пример работы экспорта студентов в файле и экспорта поля.(Примечание: чтобы экпортировать студентов в файл - загрузите файл студентов, выберете группу и нажмите кнопку Export student(в более поздних версиях программы Exports students))
Результаты работы: [Экспорт студентов](https://raw.githubusercontent.com/akapust1n/university/master/ppo/lab3/Screens/file1.txt),
[Экспорт поля](https://raw.githubusercontent.com/akapust1n/university/master/ppo/lab3/Screens/file2.txt)


### Загрузим плагин преподавателя
![With students plugin3](https://raw.githubusercontent.com/akapust1n/university/master/ppo/lab3/Screens/teacherPlugin.png)

Появилась новая кнопка и возможность загружать файлы преподавателя. Если загружен файл преподавателя, то кнопки "для студента" работать не будут, а будет работать только плагин экспорта выбранного поля. 
### Загрузим плагин старосты
![With students plugin](https://raw.githubusercontent.com/akapust1n/university/master/ppo/lab3/Screens/starostaPlugin.png)

Это грустно, но староста ничего не умеет. Поэтому если роль человека староста, то  команда старосты выведет смайл, иначе - надпись, что это не староста

### Faq

Не грузится плагин\плагины - Нужно зайти в папку нужного плагина и написать в консоли ```qmake && make```

Какая версия qt необходима для работы программы? - Работа  программы проверена на qt версии 5.9, работа на остальных версиях qt не гарантирована.
