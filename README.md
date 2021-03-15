# Simple-database-implementation

## Решение финального проекта с курса на coursera 

### [Основы разработки на C++: жёлтый пояс](https://www.coursera.org/learn/c-plus-plus-yellow)

## Пример работы БД

### stdin

    Add 2017-11-21 Tuesday
    Add 2017-11-20 Monday
    Add 2017-11-21 Weekly meeting
    Print
    Find event != "Weekly meeting"
    Last 2017-11-30
    Del date > 2017-11-20
    Last 2017-11-30
    Last 2017-11-01

### stdout

    2017-11-20 Monday
    2017-11-21 Tuesday
    2017-11-21 Weekly meeting
    2017-11-20 Monday
    2017-11-21 Tuesday
    Found 2 entries
    2017-11-21 Weekly meeting
    Removed 2 entries
    2017-11-20 Monday
    No entries



## Введение
---
- <strong>Add date event</strong> — добавить в базу данных пару <strong>(date, event)</strong>;

- <strong>Print</strong> — вывести всё содержимое базы данных;

- <strong>Find condition</strong> — вывести все записи, содержащиеся в базе данных, которые удовлетворяют условию <strong>condition</strong>;

- <strong>Del condition</strong> — удалить из базы все записи, которые удовлетворяют условию <strong>condition</strong>;

- <strong>Last date</strong> — вывести запись с последним событием, случившимся не позже данной даты.


## Формат ввода и вывода

В стандартном вводе содержатся команды для работы с базой данных, по одной команде в строке. Ваша программа должна считать их и вывести результаты обработки в стандартный вывод. Правила обработки команд приведены ниже.

## Команда Add

Встретив команду <strong>Add date event</strong>, ваша программа должна добавить пару <strong>(date, event)</strong> в базу данных и затем показывать её при поиске (команда Find) или печати (команда Print). Одинаковые события, произошедшие в один и тот же день, сохранять не нужно: добавление в базу уже существующей пары <strong>(date, event)</strong> должно игнорироваться. В одну и ту же дату может произойти много разных событий, БД должна суметь их все сохранить.

### Пример

Для команды <strong>Add 2017-11-07 big sport event</strong> программа должна добавить в базу данных пару <strong>(2017-11-07, big sport event)</strong>.

## Команда Del

Встретив команду <strong>Del condition</strong>, ваша программа должна удалить из базы данных все события, удовлетворяющие условию <strong>condition</strong>, и вывести в стандартный вывод количество удалённых записей <strong>N</strong> в формате <strong>«Removed N entries»</strong>. Если условие пусто, результатом выполнения команды должна стать очистка всей базы данных.

### Пример

### Ввод

    Add 2017-06-01 1st of June
    Add 2017-07-08 8th of July
    Add 2017-07-08 Someone's birthday
    Del date == 2017-07-08

### Вывод

    Removed 2 entries

## Команда Print

Встретив команду <strong>Print</strong>, ваша программа должна вывести все пары <strong>(дата, событие)</strong>, которые в данный момент содержатся в базе данных. Пары надо выводить по одной в строке. Они должны быть отсортированы по дате по возрастанию. События в рамках одной даты необходимо выводить в порядке добавления (за исключением уже удалённых и попыток добавления повторов)

### Пример

### Ввод

    Add 2017-01-01 Holiday
    Add 2017-03-08 Holiday
    Add 2017-1-1 New Year
    Add 2017-1-1 New Year
    Print

### Вывод

    2017-01-01 Holiday
    2017-01-01 New Year
    2017-03-08 Holiday

## Команда Find

Встретив команду <strong>Find condition</strong>, ваша программа должна вывести все пары <strong>(дата, событие)</strong>, которые в данный момент содержатся в базе данных и удовлетворяют условию <strong>condition</strong>.

### Пример

### Ввод

    Add 2017-01-01 Holiday
    Add 2017-03-08 Holiday
    Add 2017-01-01 New Year
    Find event != "working day"
    Add 2017-05-09 Holiday

### Вывод

    2017-01-01 Holiday
    2017-01-01 New Year
    2017-03-08 Holiday
    Found 3 entries

## Команда Last

По команде <strong>Last date</strong> нужно вывести последнее из событий, случившихся к дате <strong>date</strong>. 

- если date меньше всех имеющихся дат, необходимо вывести «No entries».

Пример

    Add 2017-01-01 New Year
    Add 2017-03-08 Holiday
    Add 2017-01-01 Holiday
    Last 2016-12-31
    Last 2017-01-01
    Last 2017-06-01
    Add 2017-05-09 Holiday

Ввод

    No entries
    2017-01-01 Holiday
    2017-03-08 Holiday



сертификаты:

[Основы разработки на C++: жёлтый пояс](https://coursera.org/share/2fb5c671278422043777a1310d6fab05)

[Основы разработки на C++: белый пояс](https://coursera.org/share/1abbaba6f8866c942ab093b9e902bcd6)