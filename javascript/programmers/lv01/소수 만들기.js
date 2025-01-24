// https://school.programmers.co.kr/learn/courses/30/lessons/12977
function getCombinations(array, r) {
  const result = [];

  function combine(current, start) {
    if (current.length === r) {
      result.push([...current]);
      return;
    }

    for (let i = start; i < array.length; i++) {
      current.push(array[i]);
      combine(current, i + 1);
      current.pop();
    }
  }

  combine([], 0);
  return result;
}

function isPrime(num) {
  if (num <= 1) return false;

  for (let i = 2; i <= Math.sqrt(num); i++) {
    if (num % i === 0) {
      return false;
    }
  }
  return true;
}

function solution(nums) {
  let result = 0;
  getCombinations(nums, 3).forEach((arr) => {
    const sum = arr.reduce((acc, cur) => acc + cur, 0);
    if (isPrime(sum) === true) {
      result++;
    }
  });

  return result;
}
