// https://school.programmers.co.kr/learn/challenges?tab=all_challenges&challenge_collection_part_ids%5B%5D=12286&order=acceptance_desc&gad_source=1&gclid=CjwKCAiAt4C-BhBcEiwA8Kp0CUIxZcfRR2-mgQiQGnHPsSk286vTiYY-zn5KQWghMLaH5Ezk7mCC1hoCWgoQAvD_BwE&levels=2&languages=javascript&page=1&search=%EB%A9%80%EB%A6%AC%EB%9B%B0%EA%B8%B0
function solution(n) {
  let dp = new Array(n + 1).fill(0);
  dp[1] = 1;
  dp[2] = 2;

  for (let i = 3; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
  }

  return dp[n];
}
