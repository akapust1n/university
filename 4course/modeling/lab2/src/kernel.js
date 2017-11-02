var EPS = 1e-5;


function run() {
    let tableData = document.getElementById("tbl-data");

    let matrix = [];

    for (let r = 1, n = tableData.rows.length; r < n; r++) {
        matrix[r - 1] = [];

        for (let c = 1, m = tableData.rows[r].cells.length; c < m; c++) {
            matrix[r - 1][c - 1] = parseInt(tableData.rows[r].cells[c].innerText);

            if (isNaN(matrix[r - 1][c - 1])) {
                matrix[r - 1][c - 1] = 0;
            }
        }
    }

    let koefKolmagorof = getKoefKolmagorof(matrix);
    let koefSLAU = getKoefSLAU(koefKolmagorof);

    let ans = []
    let tableResult = document.getElementById("tbl-result");

    if (gauss(koefSLAU, ans) != 1) {
        console.log("ERROR GAUSS");

        for (let c = 1, m = tableData.rows[1].cells.length; c < m; c++) {
            tableResult.rows[1].cells[c].innerText = NaN;
        }

        return;
    }
    for (let i = 1; i < matrix.rows.length; i++) {
        let sum = 0
        for (let j = 0; j < matrix.rows.length; j++) {
            if (i != j) {
                sum += matrix[i][j]
            }
        }
        console.log(sum)
        ans[i] /= sum;
    }

    for (let c = 1, m = tableData.rows[1].cells.length; c < m; c++) {
        tableResult.rows[1].cells[c].innerText = ans[c - 1].toFixed(2);
    }

}

function getKoefKolmagorof(matrix) {
    let result = [];
    for (let i = 0, n = matrix.length; i < n; ++i) {
        result[i] = [];

        for (let j = 0, m = matrix[i].length; j < m; ++j) {
            result[i][j] = 0;
        }
    }

    for (let i = 0, n = matrix.length; i < n; ++i) {
        for (let j = 0, m = matrix[i].length; j < m; ++j) {
            result[i][i] -= matrix[i][j];
        }
    }

    for (let i = 0, n = matrix.length; i < n; ++i) {
        for (let j = 0, m = matrix[i].length; j < m; ++j) {
            result[j][i] += matrix[i][j];
        }
    }

    return result;
}

function getKoefSLAU(matrix) {
    let addNormEquation = [];
    for (let i = 0, n = matrix[0].length; i < n; ++i) {
        addNormEquation.push(1);
    }
    matrix.unshift(addNormEquation);

    for (let i = 1, n = matrix[0].length + 1; i < n; ++i) {
        matrix[i].push(0);
    }
    matrix[0].push(1);

    return matrix;
}

function gauss(a, ans) {
    let n = a.length;
    let m = a[0].length - 1;


    let where = [];
    for (let i = 0; i < m; ++i) where.push(-1);

    for (let col = 0, row = 0; col < m && row < n; ++col) {
        let sel = row;

        for (let i = row; i < n; ++i)
            if (Math.abs(a[i][col]) > Math.abs(a[sel][col]))
                sel = i;

        if (Math.abs(a[sel][col]) < EPS)
            continue;

        for (let i = col; i <= m; ++i) {
            let c = a[sel][i];
            a[sel][i] = a[row][i];
            a[row][i] = c;
        }
        where[col] = row;

        for (let i = 0; i < n; ++i)
            if (i != row) {
                let c = a[i][col] / a[row][col];
                for (let j = col; j <= m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
            ++row;
    }

    for (let i = 0; i < m; ++i) ans.push(0);

    for (let i = 0; i < m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    // for (let i = 0; i < n; ++i) {
    //     let sum = 0;
    //     for (let j = 0; j < m; ++j)
    //         sum += ans[j] * a[i][j];
    //     if (Math.abs(sum - a[i][m]) > EPS)
    //         return 0;
    // }

    for (let i = 0; i < m; ++i)
        if (where[i] == -1)
            return Infinity;

    return 1;
}