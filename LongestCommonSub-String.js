/*
 * Finds the Longest Common Sub-String in the list of Strings
 *
 * @param {Array<String>} strings The list of Strings
 * @returns the Longest Common Sub-String
 */
function lcs(strings) {
  if (strings.length < 2) {
    return '';
  }
  
  let lcs = '',
      stringSet = [],
      result = [];
  
  console.log(strings[0], strings[1]);
  
  for (let i = 0; i < strings[0].length; i++) {
    let j = i,
        tempString = '';

    for (let k = 0; k < strings[1].length; k++) {
      if (strings[0][j] === strings[1][k]) {
        tempString += strings[0][j];
        j++;
      }
      else if (tempString) {
        if (!stringSet[tempString]) {
          stringSet[tempString] = tempString.length;
        }
        tempString = '';
      }
    }
    
    if(tempString && !stringSet[tempString]) {
      stringSet[tempString] = tempString.length;
    }
  }
  
  for (let i = 2; i < strings.length; i++) {
    for(let k of Object.keys(stringSet)) {
      if (strings[i].indexOf(k) === -1) {
        delete stringSet[k];
      }
    }
    
    if (!Object.keys(stringSet).length) {
      break;
    }
  }
  
  for(let k of Object.keys(stringSet)) {
    if (stringSet[k] > lcs.length) {
      lcs = k;
    }
  }

  return lcs;
}

/*
 * Finds the Longest Common Sub-String in the list of Strings.
 * Uses Binary Search to keep a sorted list of possible results.
 *
 * @param {Array<String>} strings The list of Strings
 * @returns the Longest Common Sub-String
 */
function lcsDNC(strings) {
  if (strings.length < 2) {
    return '';
  }
  
  let lcs = '',
      stringSet = [],
      result = [];
  
  for (let i = 0; i < strings[0].length; i++) {
    let j = i,
        tempString = '';

    for (let k = 0; k < strings[1].length; k++) {
      if (strings[0][j] === strings[1][k]) {
        tempString += strings[0][j];
        j++;
      }
      else if (tempString) {
        if (!stringSet[tempString]) {
          stringSet[tempString] = true;
          result = dncInsert(tempString, result, result.length / 2 >> 0);
        }
        
        tempString = '';
      }
    }
    
    if(tempString && !stringSet[tempString]) {
      stringSet[tempString] = true;
      result = dncInsert(tempString, result, result.length / 2 >> 0);
    }
  }
  
  for (let i = 2; i < strings.length; i++) {
    for(let k of Object.keys(result)) {
      if (strings[i].indexOf(result[k]) === -1) {
        delete result[k];
      }
    }
    
    if (!Object.keys(result).length) {
      break;
    }
  }
  
  if (Object.keys(result).length) { 
    lcs = result[Object.keys(result)[Object.keys(result).length - 1]];
  }
  
  return lcs;
}

/*
 * Uses Binary Search to find the element position in result
 * and inserts it shifting the other elements.
 *
 * @param {String} element The element to be inserted
 * @param {Array<String>} The array with the sorted elements
 * @param {Integer} index Current position in the sorted array
 *
 * returns {Array<String>} The new sorted array with element included
 */
function dncInsert(element, result, index) {
  if (!result.length) {
    result.push(element);
    return result;
  }
  
  if (index < 0) {
    result = [element].concat(result);
    return result;
  }
  
  if (element.length >= result[index].length) {
    if (!result[index + 1]) {
      result.push(element);
      return result;
    }
    
    if (element.length > result[index + 1].length) {
      return dncInsert(element, result, index + ((result.length - index) / 2 >> 0));
    }
    
    let temp = result[index + 1];
    
    result[index + 1] = element;
    return dncInsert(temp, result, index + 1);
  }
  
  return dncInsert(element, result, index - 1);
}

// Unit Tests
// Put the list of strings in the first element of the array
// And the solution in the second element of the array
let testCases = [
  [[], ['']],
  [[''], ['']],
  [['', ''], ['']],
  [['ABABC', ''], ['']],
  [['ABABC', 'BABCA'], ['BABC']],
  [['ABABC', 'BABCA', 'ABCBA'], ['ABC']],
  [['ABABC', 'BABCA', 'ABCBA', 'XMNBAKBH BASKDAB'], ['AB']],
  [['CHZVFRKMLNOZJK', 'PQPXRJXKITZYXACBHHKICQCOENDTOMFGDWDWFCGPXIQVKUYTDLCGDEWHTACIOHORDTQKVWCSGSPQOQMSBOAGUWN'], ["C", "H", "V", "R", "M", "N", "J", "O", "L", "K", "F", "Z"]],
  [['Lorem', 'ipsum', 'dolor', 'sit', 'amet', 'consectetur', 'adipiscing', 'elit', 'Integer', 'nec', 'odio', 'Praesent', 'libero', 'Sed', 'cursus', 'ante', 'dapibus', 'diam', 'Sed', 'nisi', 'Nulla', 'quis', 'sem', 'at', 'nibh', 'elementum', 'imperdiet', 'Duis', 'sagittis', 'ipsum', 'Praesent', 'mauris', 'Fusce', 'nec', 'tellus', 'sed', 'augue', 'semper', 'porta', 'Mauris', 'massa', 'Vestibulum', 'lacinia', 'arcu', 'eget', 'nulla', 'Class', 'aptent', 'taciti', 'sociosqu', 'ad', 'litora', 'torquent', 'per', 'conubia', 'nostra', 'per', 'inceptos', 'himenaeos', 'Curabitur', 'sodales', 'ligula', 'in', 'libero', 'Sed', 'dignissim', 'lacinia', 'nunc', 'Curabitur', 'tortor', 'Pellentesque', 'nibh', 'Aenean', 'quam', 'In', 'scelerisque', 'sem', 'at', 'dolor', 'Maecenas', 'mattis', 'Sed', 'convallis', 'tristique', 'sem', 'Proin', 'ut', 'ligula', 'vel', 'nunc', 'egestas', 'porttitor', 'Morbi', 'lectus', 'risus', 'iaculis', 'vel', 'suscipit', 'quis', 'luctus', 'non', 'massa', 'Fusce', 'ac', 'turpis', 'quis', 'ligula', 'lacinia', 'aliquet', 'Mauris', 'ipsum', 'Nulla', 'metus', 'metus', 'ullamcorper', 'vel', 'tincidunt', 'sed', 'euismod', 'in', 'nibh', 'Quisque', 'volutpat', 'condimentum', 'velit', 'Class', 'aptent', 'taciti', 'sociosqu', 'ad', 'litora', 'torquent', 'per', 'conubia', 'nostra', 'per', 'inceptos', 'himenaeos', 'Nam', 'nec', 'ante', 'Sed', 'lacinia', 'urna', 'non', 'tincidunt', 'mattis', 'tortor', 'neque', 'adipiscing', 'diam', 'a', 'cursus', 'ipsum', 'ante', 'quis', 'turpis', 'Nulla', 'facilisi', 'Ut', 'fringilla', 'Suspendisse', 'potenti', 'Nunc', 'feugiat', 'mi', 'a', 'tellus', 'consequat', 'imperdiet', 'Vestibulum', 'sapien', 'Proin', 'quam', 'Etiam', 'ultrices', 'Suspendisse', 'in', 'justo', 'eu', 'magna', 'luctus', 'suscipit', 'Sed', 'lectus', 'Integer', 'euismod', 'lacus', 'luctus', 'magna', 'Quisque', 'cursus', 'metus', 'vitae', 'pharetra', 'auctor', 'sem', 'massa', 'mattis', 'sem', 'at', 'interdum', 'magna', 'augue', 'eget', 'diam', 'Vestibulum', 'ante', 'ipsum', 'primis', 'in', 'faucibus', 'orci', 'luctus', 'et', 'ultrices', 'posuere', 'cubilia', 'Curae;', 'Morbi', 'lacinia', 'molestie', 'dui', 'Praesent', 'blandit', 'dolor', 'Sed', 'non', 'quam', 'In', 'vel', 'mi', 'sit', 'amet', 'augue', 'congue', 'elementum', 'Morbi', 'in', 'ipsum', 'sit', 'amet', 'pede', 'facilisis', 'laoreet', 'Donec', 'lacus', 'nunc', 'viverra', 'nec'], ''],
  [['Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!', 'Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!'], ['Hodor, hodor hodor hodor - hodor hodor hodor?! Hodor hodor HODOR! Hodor hodor hodor hodor hodor hodor, hodor, hodor hodor. Hodor! Hodor hodor, hodor hodor hodor hodor! Hodor. Hodor HODOR hodor, hodor hodor - HODOR hodor, hodor hodor, hodor, hodor hodor. Hodor hodor... Hodor hodor hodor - hodor?!']],
  [['ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz'], ['ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz']],
  [['ABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVQXYZ 0123456789 abcdefghijklmnopqrstuvwxyz'], ['ABCDEFGHIJKLMNOPQRSTUVQXYZ', 'abcdefghijklmnopqrstuvwxyz']]
]

for (let i = 0; i < testCases.length; i++) {
  let result,
      testCase = testCases[i];
  
  console.log("Test Case " + (i + 1));
  console.log("Solving [" + testCase[0] + "]");
  console.log("Solutions: [" + testCase[1] + "]");
  document.body.innerHTML += "<b>Test Case " + (i + 1) + "</b><BR/>";
  document.body.innerHTML += "Solutions: [" + testCase[1] + "]<BR/>";
  
  logResults('Without Binary Search', lcs, testCase[0], testCase[1]);
  logResults('Using Binary Search', lcsDNC, testCase[0], testCase[1]);
  
  document.body.innerHTML += "<BR/>";
  console.log("--------------------------------------------------------------------------------");
}

document.body.innerHTML += "<i>For performance information, check the Browser console log.</i>"

/*
 * Helper function to log the results in the console and also in the HTML
 *
 * @param {String} label Label for the test run
 * @param {function} func Function to call to solve the test case
 * @param {*} testCase Expected input for the func
 * @param {Array<String>} expectedResult Array of expected results
 */
function logResults(label, func, testCase, expectedResult) {
  console.time(label);
  result = func(testCase);
  console.timeEnd(label);
  
  console.assert(expectedResult.indexOf(result) !== -1, result);
  document.body.innerHTML += label + ": ";
  
  if (expectedResult.indexOf(result) === -1) {
    document.body.innerHTML += "<span style='color: red'>FAIL:</span> '" + result + "'<BR/>";
  }
  else {
    document.body.innerHTML += "<span style='color: green'>Passed: '" + result + "'</span><BR/>";
  }
}
