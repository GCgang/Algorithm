// https://school.programmers.co.kr/learn/courses/30/lessons/1845
function solution(nums) {
  const uniqueTypes = new Set(nums);
  const maxSelection = nums.length / 2;

  return Math.min(uniqueTypes.size, maxSelection);
}
