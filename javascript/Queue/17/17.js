class Queue {
  items = [];
  front = 0;
  rear = 0;

  constructor(array) {
    this.items = array;
    this.rear = array.length;
  }
  push(item) {
    this.items.push(item);
    this.rear++;
  }

  pop() {
    return this.items[this.front++];
  }

  getFront() {
    return this.items[this.front];
  }

  isEmpty() {
    return this.front === this.rear;
  }
}
function solution(cards1, cards2, goal) {
  let answer = [];
  const q1 = new Queue(cards1);
  const q2 = new Queue(cards2);

  for (let i = 0; i < goal.length; ++i) {
    if (!q1.isEmpty() && goal[i] === q1.getFront()) {
      answer.push(q1.pop());
    } else if (!q2.isEmpty() && goal[i] === q2.getFront()) {
      answer.push(q2.pop());
    } else {
      break;
    }
  }

  if (answer.join(' ') === goal.join(' ')) {
    return 'Yes';
  } else {
    return 'No';
  }
}
