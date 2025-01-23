// https://school.programmers.co.kr/learn/courses/30/lessons/86491
function solution(sizes) {
  let maxWidth = 0;
  let maxHeight = 0;

  for (let [w, h] of sizes) {
    const [long, short] = w > h ? [w, h] : [h, w];

    maxWidth = Math.max(long, maxWidth);
    maxHeight = Math.max(short, maxHeight);
  }

  return maxWidth * maxHeight;
}
