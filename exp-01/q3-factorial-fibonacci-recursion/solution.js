const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

function fib(n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

function fact(n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

rl.on('line', (line) => {
    const n = parseInt(line.trim(), 10);
    let series = [];
    for (let i = 0; i < n; i++) series.push(fib(i));
    console.log(`Fibonacci series (${n} terms): ${series.join(' ')}`);
    console.log(`Factorial of ${n}: ${fact(n)}`);
    rl.close();
});