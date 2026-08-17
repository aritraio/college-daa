const readline = require("readline");

function partition(arr, low, high) {
    const pivot = arr[high];
    let i = low - 1;
    for (let j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            [arr[i], arr[j]] = [arr[j], arr[i]];
        }
    }
    [arr[i + 1], arr[high]] = [arr[high], arr[i + 1]];
    return i + 1;
}

function quickSort(arr, low, high) {
    if (low < high) {
        const pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

const rl = readline.createInterface({ input: process.stdin });
const lines = [];

rl.on("line", (line) => lines.push(line));

rl.on("close", () => {
    const nums = lines.join(" ").trim().split(/\s+/).map(Number);
    const n = nums[0];
    const arr = nums.slice(1, 1 + n);
    quickSort(arr, 0, n - 1);
    console.log(arr.join(" "));
});