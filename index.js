var arr = [
  { Name: "Deepanshu", Age: 21 },
  { Name: "Bhumi", Age: 16 },
  { Name: "Aman", Age: 50 },
  { Name: "Dhiru", Age: 40 },
];
console.log(arr);

const isValid = arr.filter((item) => {
  return item.Age > 18;
});

const sumArr = arr.reduce((acc, item) => (acc += item.Age), 0);

let sum = 0;
for (let i = 0; i < arr.length; i++) {
  sum += arr[i].Age;
}

let summm = 0;

arr.forEach((item) => (summm += item.Age));

arr.splice({ Name: "Naaam", Age: 210 });

// console.log(arr)

// const fruits = ["Banana dsfsdfsdfsd dsfdsfs"];
// const myBest = fruits.slice(" ");
// console.log(myBest);

// const arrrr=[4,3,2,5,3,6,'a',600,'b',true,false];
// arrrr.sort();
// console.log(arrrr);

const matrix = [
  [1, 2, 3],
  [3, 2, 1],
  [4, 5, 3, 2],
  [1, [3, 4, [4, 5, 6]]],
];
let name = "ramdfsdf";
let k = Array.from(name);
console.log(matrix);
const flatted = matrix.flat(3);
console.log(k);

let arr3 = new Array();
arr3.push(5);
arr3 = [1, 23, 4, 5, 9, 8];
arr3.pop();
console.log(arr3);
