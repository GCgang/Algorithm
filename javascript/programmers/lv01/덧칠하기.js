// https://school.programmers.co.kr/learn/courses/30/lessons/161989

// 그리디
function solution(n, m, section) {
  let cnt = 0;
  let lastPainted = 0;

  for (const start of section) {
    if (start > lastPainted) {
      cnt++;
      lastPainted = start + m - 1;
    }
  }
  return cnt;
}

// 슬라이딩 윈도우
function solution1(n, m, section) {
  let cnt = 0;
  let i = 0;

  while (i < section.length) {
    cnt++;
    const end = section[i] + m - 1;

    while (i < section.length && section[i] <= end) {
      i++;
    }
  }
  return cnt;
}

// queue
function solution2(n, m, section) {
  const queue = [...section];
  let cnt = 0;

  while (queue.length > 0) {
    const start = queue.shift();
    cnt++;

    while (queue.length > 0 && queue[0] <= start + m - 1) {
      queue.shift();
    }
  }
  return cnt;
}

// 이분탐색
function solution3(n, m, section) {
  let count = 0;
  let i = 0;
  while (i < section.length) {
    count++;
    const end = section[i] + m - 1;

    let left = i,
      right = section.length - 1;
    while (left <= right) {
      const mid = Math.floor((left + right) / 2);
      if (section[mid] <= end) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    i = left;
  }

  return count;
}
