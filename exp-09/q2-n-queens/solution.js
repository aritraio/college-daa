const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });

const MAX = 100;
const board = new Array(MAX).fill(0);
let n;
let count = 0;

function isSafe(row, col) {
    for (let i = 0; i < row; i++) {
        if (board[i] === col || Math.abs(board[i] - col) === Math.abs(i - row))
            return false;
    }
    return true;
}

function solve(row) {
    if (row === n) {
        const cols = [];
        for (let i = 0; i < n; i++) cols.push(board[i] + 1);
        console.log(cols.join(' '));
        count++;
        return;
    }
    for (let col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

rl.on('line', (line) => {
    n = parseInt(line.trim(), 10);
    solve(0);
    console.log(`Total solutions: ${count}`);
    rl.close();
});
