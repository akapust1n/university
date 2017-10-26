function createTableData(numRows, numCells) {
    var title = document.createElement("h2");
    title.innerText = "Таблица данных";
    document.body.appendChild(title);

    let table = document.createElement("table");
    table.id = "tbl-data";
    table.width = 400;
    table.border = 1;

    let titleRow = table.insertRow(-1);
    let newCell = titleRow.insertCell(-1);
    newCell.classList.add("head");
    newCell.innerText = "из\\в";


    for (let j = 0; j < numCells; ++j) {
        let newCell = titleRow.insertCell(-1);
        newCell.innerText = "S" + j;
        newCell.classList.add("head");
    }

    for (let i = 0; i < numRows; ++i) {
        let newRow = table.insertRow(-1);
        let newCell = newRow.insertCell(-1);
        newCell.innerText = "S" + i;
        newCell.classList.add("left-hand");

        for (let j = 0; j < numCells; ++j) {
            let newCell = newRow.insertCell(-1);

            newCell.contentEditable = "true";
            newCell.innerText = "";
            newCell.classList.add("data");
        }
    }

    document.body.appendChild(table);
}

function createTableResult(numCells) {
    var title = document.createElement("h2");
    title.innerText = "Таблица результатов";
    document.body.appendChild(title);


    var table = document.createElement("table");
    table.id = "tbl-result";
    table.width = 400;
    table.border = 1;

    let titleRow = table.insertRow(-1);
    let newCell = titleRow.insertCell(-1);
    newCell.classList.add("head");

    for (let j = 0; j < numCells; ++j) {
        let newCell = titleRow.insertCell(-1);
        newCell.innerText = "S" + j;
        newCell.classList.add("head");
    }

    let newRow = table.insertRow(-1);
    newCell = newRow.insertCell(-1);
    newCell.classList.add("left-hand");
    newCell.innerText = "T:";

    for (let j = 0; j < numCells; ++j) {
        let newCell = newRow.insertCell(-1);
        newCell.classList.add("data");
    }

    document.body.appendChild(table);
}

numStates = parseInt(prompt("Введите кол-во состояний системы", "4"));

createTableData(numStates, numStates);
createTableResult(numStates);