/*
 * Definirion for a N-Ary Tree Node class
 *
 * @param {*} value The Node value
 */
function Node(value) {
  this.value = value;
  this.children = [];
};

/*
 * (Utilizes N-Ary Tree)
 * Takes in an expression that uses curly brackets { to denote
 * modifications to normal order of operations (like parenthesis
 * for mathematical expressions) and return the parsed expression.
 * 
 * For example, the expression: "a{b{c d} e{f}}" 
 * Would return: "abc abd aef"
 *
 * @param {String} expr The expression to be parsed
 * @returns {String} The parsed expression
 */
function solveWithTree(expr) {
  if (!expr || !expr.length) {
    return expr;
  }
  
  let head = new Node(""),
      result = [];

  constructTree(expr, head, 0);
  deconstructTree(head, "", result);
  
  return result.join(' ');
};

/*
 * Takes in an expression that uses curly brackets { to denote
 * modifications to normal order of operations (like parenthesis
 * for mathematical expressions) and return the parsed expression.
 * 
 * For example, the expression: "a{b{c d} e{f}}" 
 * Would return: "abc abd aef"
 *
 * @param {String} expr The expression to be parsed
 * @returns {String} The parsed expression
 */
function solveWithoutTree(expr) {
  if (!expr || !expr.length) {
    return expr;
  }
  
  let result = [];
  
  noTreeSolver(expr, 0, "", result);
  
  return result.join(' ');
};

/*
 * Runs through the string recursing when a new expression is found
 *
 * @param {String} str The expression to be parsed
 * @param {Integer} index The current position in str
 * @param {String} expr The parsed expression being constructed
 * @param {Array{String}} result The array containing each expression parcel
 */
function noTreeSolver(str, index, expr, result) {
  let value = "";
  
  while (index < str.length) {
    if (str[index] === '{') {
      index = noTreeSolver(str, index + 1, expr + value, result);
      value = "";
    }
    
    else if (str[index] === '}') {
      if (value.length) {
        result.push(expr + value);
      }
      
      return index + 1;
    }
    
    else if (str[index] === ' ') {
      if (value.length) {
        result.push(expr + value);
        value = "";
      }
      
      index++;
    }
    
    else {
      value += str[index++];
    }
  }
  
  if (value.length) {
    result.push(expr + value);
  }
};

/*
 * Goes through the expression string and constructs a N-Ary tree
 * based on the parcels of the expression.
 *
 * @param {String} str The expression string to be parsed
 * @param {Node} head The N-Ary Tree Node
 * @param {Integer} index The current position in str
 */
function constructTree(str, head, index) {
  let value = "";
  
  while (index < str.length) {
    if (str[index] === '{') {
      let node = new Node(value);
      
      head.children.push(node);
      index = constructTree(str, node, index + 1);
      value = "";
    }
    
    else if (str[index] === '}') {
      if (value.length) {
        head.children.push(new Node(value));
      }
      
      return index + 1;
    }
    
    else if (str[index] === ' ') {
      if (value.length) {
        head.children.push(new Node(value));
        value = "";
      }
      
      index++;
    }
    
    else {
      value += str[index++];
    }
  }
  
  if (value.length) {
    head.children.push(new Node(value));
  }
};

/*
 * Goes through the N-Ary Tree recreating the expression
 * and pushing the parcels to the result Array.
 *
 * @param {Node} head The N-Ary Tree head
 * @param {String} str The expression parcel being constructed
 * @param {Array{String}} result The array containing each expression parcel
 */
function deconstructTree(head, str, result) {    
  if (!head.children.length) {
    result.push(str + head.value);
    
    return;
  }
  
  for (let i = 0; i < head.children.length; i++) {    
    deconstructTree(head.children[i], str + head.value, result);
  }
};

// Unit Tests
// Put the expression in the first element of the array
// And the solution in the second element of the array
let expr = [
  ["a{b c}", "ab ac"],
  ["a{b{c d} e{f}}", "abc abd aef"],
  ["a", "a"],
  ["", ""],
  ["ab", "ab"],
  ["a b", "a b"],
  ["a{b{c d", "abc abd"],
  ["a{b c{d e f{a} g}}", "ab acd ace acfa acg"],
  ["b a{n n} a", "b an an a"],
  ["abc{def ghijklm{n opqr} st{uvwx}} yz", "abcdef abcghijklmn abcghijklmopqr abcstuvwx yz"]
];

for (let i = 0; i < expr.length; i++) {
  let res;
  
  document.body.innerHTML += "<b>Solving " + expr[i][0] + "</b><BR/>";
  console.log("Solving", expr[i][0]);
  
  // Solve using Tree and measure time
  console.time('Using N-Ary Tree');
  res = solveWithTree(expr[i][0]);
  console.timeEnd('Using N-Ary Tree');
  
  console.assert(res === expr[i][1], "'" + res + "' should be '" + expr[i][1] + "'");
  document.body.innerHTML += "Using N-Ary Tree ";
  
  if (res !== expr[i][1]) {
    document.body.innerHTML += "<span style='color: red'>FAIL:</span> '" + 
      res + "' <i>should be</i> '" + expr[i][1] + "'<BR/>";
  }
  else {
    document.body.innerHTML += "<span style='color: green'>Passed</span><BR/>";
  }
  
  // Solve without using Tree and measure time.
  console.time('Without N-Ary Tree');
  res = solveWithoutTree(expr[i][0])
  console.timeEnd('Without N-Ary Tree');
  
  console.assert(res === expr[i][1], "'" + res + "' should be '" + expr[i][1] + "'");
  document.body.innerHTML += "Without N-Ary Tree ";
  
  if (res !== expr[i][1]) {
    document.body.innerHTML += "<span style='color: red'>FAIL:</span> '" 
      + res + "' <i>should be</i> '" + expr[i][1] + "'<BR/>";
  }
  else {
    document.body.innerHTML += "<span style='color: green'>Passed</span><BR/>";
  }
  
  console.log("------------------------------------");
  document.body.innerHTML += "<BR/>";
}

document.body.innerHTML += "<i>For performance information, check the Browser console log.</i>"
