class Queue {
  items = [];
  front = 0;
  rear = 0;

  push(item) {
    this.items.push(item);
    this.rear++;
  }
  pop() {
    return this.items[this.front++];
  }
  size() {
    return this.rear - this.front;
  }
}
function solution(N, K) {
  const q = new Queue();

  for (let i = 1; i <= N; ++i) {
    q.push(i);
  }

  while (q.size() > 1) {
    for (let i = 0; i < K - 1; ++i) {
      q.push(q.pop());
    }
    q.pop();
  }
  return q.pop();
}

console.log(solution(5, 2)); // 3
