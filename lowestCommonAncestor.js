/**
 * Definition for a binary tree node.
 */
function TreeNode(val) {
  this.val = val;
  this.left = this.right = null;
}

TreeNode.prototype.findLowestCommonAncestor = function(p, q) {
  if (!this || this === p || this === q) {
    return this;
  }
  
  let left = this.left ? this.left.findLowestCommonAncestor(p, q) : null,
      right = this.right ? this.right.findLowestCommonAncestor(p, q) : null;
  
  return !left ? right : (!right ? left : this);
};

/**
 * @param {TreeNode} root
 * @param {TreeNode} a
 * @param {TreeNode} b
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    return root.findLowestCommonAncestor(p, q);
};
