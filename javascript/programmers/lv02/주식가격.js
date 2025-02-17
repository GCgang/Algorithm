//https://school.programmers.co.kr/learn/courses/30/lessons/42584
// O(N)
function solution(prices) {
  let result = Array(prices.length).fill(0);
  let stack = [];

  for (let i = 0; i < prices.length; i++) {
    while (stack.length > 0 && prices[stack[stack.length - 1]] > prices[i]) {
      let idx = stack.pop();
      result[idx] = i - idx;
    }
    stack.push(i);
  }

  while (stack.length > 0) {
    let idx = stack.pop();
    result[idx] = prices.length - 1 - idx;
  }
  return result;
}

// O(N^2)
function solution2(prices) {
  const result = Array(prices.length).fill(0);

  for (let i = 0; i < prices.length; i++) {
    for (let j = i + 1; j < prices.length; j++) {
      result[i]++;
      if (prices[i] > prices[j]) break;
    }
  }
  return result;
}
