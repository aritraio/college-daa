const readline = require("readline");

function heapify(arr, n, i) {
    let largest = i;
    const left = 2 * i + 1;
    const right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest !== i) {
        [arr[i], arr[largest]] = [arr[largest], arr[i]];
        heapify(arr, n, largest);
    }
}

function heapSort(arr, n) {
    for (let i = Math.floor(n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (let i = n - 1; i > 0; i--) {
        [arr[0], arr[i]] = [arr[i], arr[0]];
        heapify(arr, i, 0);
    }
}

const rl = readline.createInterface({ input: process.stdin });
const lines = [];

rl.on("line", (line) => lines.push(line));

rl.on("close", () => {
    const nums = lines.join(" ").trim().split(/\s+/).map(Number);
    const n = nums[0];
    const arr = nums.slice(1, 1 + n);
    heapSort(arr, n);
    console.log(arr.join(" "));
});