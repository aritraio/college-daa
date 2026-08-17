const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

let count = 0;

function towerOfHanoi(n, from, to, aux) {
    if (n === 1) {
        console.log(`Move disk 1 from ${from} to ${to}`);
        count++;
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    console.log(`Move disk ${n} from ${from} to ${to}`);
    count++;
    towerOfHanoi(n - 1, aux, to, from);
}

rl.on('line', (line) => {
    const n = parseInt(line.trim(), 10);
    towerOfHanoi(n, 'A', 'C', 'B');
    console.log(`Total moves: ${count}`);
    rl.close();
});