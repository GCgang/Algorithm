function quickSort(array) {
  if (array.length <= 1) return array;

  const pivot = array[0];
  const left = [];
  const right = [];

  for (let i = 1; i < array.length; i++) {
    if (array[i] < pivot) {
      left.push(array[i]);
    } else {
      right.push(array[i]);
    }
  }

  return [...quickSort(left), pivot, ...quickSort(right)];
}

console.log(quickSort([3, 4, 1, 2, 6, 5, 2, 9, 8, 4]));
