const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

function knapsack(n, W, wt, val) {
    const dp = Array.from({ length: n + 1 }, () => Array(W + 1).fill(0));
    for (let i = 1; i <= n; i++) {
        for (let w = 1; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = Math.max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
}).on('close', () => {
    const [n, W] = lines[0].split(/\s+/).map(Number);
    const wt = [], val = [];
    for (let i = 1; i <= n; i++) {
        const [w, v] = lines[i].split(/\s+/).map(Number);
        wt.push(w);
        val.push(v);
    }
    console.log(knapsack(n, W, wt, val));
});