function solution(arr, target) {
  const numSet = new Set();

  for (let i = 0; i < arr.length; ++i) {
    const value = target - arr[i];

    if (numSet.has(value)) {
      return true;
    }
    numSet.add(arr[i]);
  }
  return false;
}

console.log(solution([1, 2, 3, 4, 8], 6));
console.log(solution([2, 3, 5, 9], 10));
