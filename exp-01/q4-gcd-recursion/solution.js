const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

function gcd(a, b) {
    if (b === 0) return a;
    return gcd(b, a % b);
}

rl.on('line', (line) => {
    const [a, b] = line.trim().split(/\s+/).map(Number);
    console.log(`GCD of ${a} and ${b}: ${gcd(a, b)}`);
    rl.close();
});