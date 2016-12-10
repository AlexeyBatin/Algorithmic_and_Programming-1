function matrixArray(rows, columns) { // Генерування матриці
    var arr = [];
    for (var i = 0; i < columns; i++) {
        arr[i] = [];
        for (var j = 0; j < rows; j++) {
            if (generate == false) arr[i][j] = +prompt("Введіть значення для елемента [ " + i + "," + j + "]");
            else {
                var min = 0,
                    max = 1;
                arr[i][j] = Math.floor(Math.random() * (max - min + 1)) + min;
            }
        }
    }
    return arr;
}

function output() { // Вивід матриці
    document.write('<table class="table table-bordered">');
    for (var i = 0; i < myMatrix.length; i++) {
        document.write("<tr>");
        for (var j = 0; j < myMatrix.length; j++) {
            document.write("<td>" + myMatrix[i][j] + "</td>");
        }
        document.write("</tr>");
    }
    document.write("</table>");
}

var ConStrSize, // зміна розміру матриці
    ask, // Рандом чи власноруч
    generate, // bool чи потрібно генерувати
    myMatrix;
ConStrSize = +prompt("Введіть розмір матриці:");
console.log("Введений розмір матриці: " + ConStrSize);
ask = prompt("Введення елементів самостійно чи рандомно?");
if (ask == "Y" || ask == "y") {
    console.info("\nВи можете вводить елементи в виді матриці\n Елементи рядку записуйте через пробіл,",
        "для переходу на наступний натисніть 'Ентер' \n Пам'ятайте, що у вас матриця розмірності " + ConStrSize + "x" + ConStrSize);
    generate = false;
    myMatrix = matrixArray(ConStrSize, ConStrSize);
    output();
} else {
    console.info("Матриця розмірності " + ConStrSize + "x" + ConStrSize + "буде згенерована рандомними значеннями");
    generate = true;
    myMatrix = matrixArray(ConStrSize, ConStrSize);
    output();
}
/////////// Алгоритм Уоршала
for (var i = 0; i < ConStrSize; i++)
{
    for (var j = 0; j < ConStrSize; j++)
    {
        if ( (i != j) && (myMatrix[i][j] != 0))
        {
            for (var k = 0; k < ConStrSize; k++)
            {
                if (myMatrix[i][k] || myMatrix[j][k])
                    myMatrix[i][k] = 1;
            }
        }
    }
}
console.log("Алгоритм Уоршала виконано");
document.write("<h2>Матриця після алгоритму Уоршала</h2>");
output();