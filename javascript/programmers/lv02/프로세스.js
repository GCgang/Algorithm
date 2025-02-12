//https://school.programmers.co.kr/learn/courses/30/lessons/42587
// O(N^2)
function solution(priorities, location) {
  const queue = priorities.map((priority, index) => ({ priority, index }));
  let executionOrder = 0;

  while (queue.length > 0) {
    const process = queue.shift();

    if (queue.some((p) => p.priority > process.priority)) {
      queue.push(process);
    } else {
      executionOrder++;
      if (process.index === location) return executionOrder;
    }
  }
}

// O(N log N)
function solution2(priorities, location) {
  let queue = priorities.map((priority, index) => ({ priority, index }));
  let sortedPriorities = [...priorities].sort((a, b) => b - a); // 우선순위 정렬 (내림차순)
  let executionOrder = 0;

  while (queue.length > 0) {
    let process = queue.shift(); // 큐에서 첫 번째 프로세스를 꺼냄

    if (process.priority === sortedPriorities[0]) {
      executionOrder++; // 실행됨
      sortedPriorities.shift(); // 실행된 프로세스를 정렬된 리스트에서도 제거
      if (process.index === location) return executionOrder; // 목표 프로세스 실행
    } else {
      queue.push(process); // 우선순위가 높지 않으면 다시 큐의 끝에 넣음
    }
  }
}
