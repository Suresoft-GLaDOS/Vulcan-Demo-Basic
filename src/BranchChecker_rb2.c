
#include "BranchChecker_rb2.h"

int cur_index_rb = 0;

// nil 생성
Node_RB make_nil = {
  .color = RBTREE_BLACK,
  .left = NULL,
  .right = NULL,
  .parent = NULL
};
Node_RB *nil = &make_nil;

// 트리 생성
rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));  // rbtree의 인자를 1개 메모리 할당(할당된 공간의 값을 모두 0으로 초기화)
  return p;
}

// RBtree 구조체가 차지했던 메모리 반환
void del_node(Node_RB * t) {
  if (t != NULL) {
    del_node(t->left);
    del_node(t->right);
  }
  free(t);
}

void delete_rbtree(rbtree *t) {
  del_node(t->root);
  free(t);
}

// 좌회전 함수
Node_RB *left_rotate(Node_RB *t, Node_RB *base) {
  Node_RB *y = base->right;
  base->right = y->left;

  if (y->left != NULL) {
    y->left->parent = base;  // 왼쪽으로 돌리기 때문에 y의 작은 수는 base 자식으로 옮겨짐
  }

  y->parent = base->parent;  // 부모 노드 옮기기

  if (base->parent == NULL) {  // base->parent가 없다면 y가 root
    t = y;
  }
  else if (base == base->parent->left) {  // base가 왼쪽에 위치한다면
    base->parent->left = y;
  }
  else {
    base->parent->right = y;
  }

  y->left = base;
  base->parent = y;

  return t;
}

// 우회전 함수
Node_RB *right_rotate(Node_RB *t, Node_RB *base) {
  Node_RB *y = base->left;
  base->left = y->right;

  if (y->right != NULL) {
    y->right->parent = base;
  }

  y->parent = base->parent;

  if (base->parent == NULL) {
    t = y;
  }
  else if (base == base->parent->right) {
    base->parent->right =y;
  }
  else {
    base->parent->left = y;
  }
  y->right = base;
  base->parent = y;

  return t;
}

void *insert_fixup(rbtree *t, Node_RB *n) {
  Node_RB *y;
  while (n->parent != NULL && n->parent->color == RBTREE_RED) {  // 부모 노드가 RED면
    if (n->parent == n->parent->parent->left) {  // 부모 노드가 조부모 노드의 왼쪽에 있다면
      y = n->parent->parent->right;  // 삼촌 노드

      if (y != NULL && y->color == RBTREE_RED) {  // 부모, 삼촌 다 RED
        n->parent->color = RBTREE_BLACK;
        y->color = RBTREE_BLACK;
        n->parent->parent->color = RBTREE_RED;
        n = n->parent->parent;  // 균열이 생기는 지점(조부모 노드가 레드로 변하면서 조건을 깰 수 있기 때문!)
      }
      else {  // 부모 노드 RED, 삼촌 노드 BLACK
        if (n == n->parent->right) {  // 현재 노드가 오른쪽에 위치한다면(부모보다 큰 수)
          n = n->parent;
          t->root = left_rotate(t->root, n);
        }
        n->parent->color = RBTREE_BLACK;
        n->parent->parent->color = RBTREE_RED;
        t->root = right_rotate(t->root, n->parent->parent);
      }
    }
    else {  // 부모 노드가 조부모 노드의 오른쪽에 있다면
      y = n->parent->parent->left;  // 삼촌 노드
      if (y != NULL && y->color == RBTREE_RED) {  // 부모, 삼촌 다 RED
        n->parent->color = RBTREE_BLACK;
        y->color = RBTREE_BLACK;
        n->parent->parent->color = RBTREE_RED;
        n = n->parent->parent;
      }
      else {
        if (n == n->parent->left) {  // 현재 노드가 왼쪽에 위치한다면
          n = n->parent;  // 로테이션 할 기준 변경
          t->root = right_rotate(t->root, n);
        }
        n->parent->color = RBTREE_BLACK;
        n->parent->parent->color = RBTREE_RED;
        t->root = left_rotate(t->root, n->parent->parent);
      }
    }
  }
  // t->root->parent = NULL;
  t->root->color = RBTREE_BLACK;  // 루트 색은 검정!
}

Node_RB *rbtree_insert(rbtree *t, const key_t data) {
  Node_RB *y = NULL;
  Node_RB *x = t->root;

  // 새로 들어올 노드 생성
  Node_RB *n = (Node_RB *)malloc(sizeof(Node_RB));
  n->color = RBTREE_RED;
  n->data = data;
  n->left = NULL;
  n->right = NULL;

  int curData = 0;

  while (x != NULL) {  // 노드 n이 들어갈 위치 찾는 과정
    y = x;  // y는 n의 부모 노드
    curData = x->data;
    if (data < x->data) {
      x = x->left;
    }
    else if (data > x->data) {
      x = x->right;
    }
    if (curData == (int)data) {
      return n;
    }
  }


  n->parent = y;

  if (y == NULL) {  // x가 0이었다면(트리가 없었다면)
    t->root = n;
    // printf("Root: %d\n", t->root->data);
  }
  else if (data < y->data) {
    // printf("Left: %d\n", y->data);
    y->left = n;
  }
  else if (data > y->data) {
    // printf("Right: %d\n", y->data);
    y->right = n;
  }
//   else {
//     return n;
//   }

  insert_fixup(t, n);

  return n;
}

Node_RB *rbtree_find(const rbtree *t, const key_t data) {
  Node_RB *find_node;
  find_node = t->root;

  while (find_node != nil) {
    if (data == find_node->data) {
      return find_node;
    }
    if (data < find_node->data) {
      find_node = find_node->left;
    }
    else if (data > find_node->data) {
      find_node = find_node->right;
    }
    return NULL;
  }
}

Node_RB *rbtree_min(const rbtree *t) {
  Node_RB *tmp = t->root;

  while (tmp->left != NULL) {
    tmp = tmp->left;
  }
  return tmp;
}

Node_RB *rbtree_max(const rbtree *t) {
  Node_RB *tmp = t->root;

  while (tmp->right != NULL) {
    tmp = tmp->right;
  }
  return tmp;
}

/*rbtree의 특성 유지
  노드의 위치를 이동시키는 함수*/
void tree_transplant(rbtree *t, Node_RB *n1, Node_RB *n2) {
  if (n1->parent == NULL) {
    t->root = n2;
  }
  else if (n1 == n1->parent->left) {
    n1->parent->left = n2;
  }
  else {
    n1->parent->right = n2;
  }
  if (n2 != NULL){
    n2->parent = n1->parent;  // n1의 부모 노드와 n2의 부모 노드 연결
  }
}

// node_nil: x가 없을 때, 더미노드 nil 반환
Node_RB *node_nil(Node_RB *x) {
  if (x == NULL) {
    return nil;
  }
  else {
    return x;
  }
}

// successor
Node_RB *successor(rbtree *t, Node_RB *x) {
  if (x->right != NULL) {  // x의 우노드가 존재할 때, 서브트리의 최소값 찾기
    Node_RB *c = x->right;
    while (c->left != NULL) {
      c = c->left;
    }
    return c;
  }
  Node_RB *p = x->parent;
  while (p != NULL && x == p->right) {  // x의 우노드가 없을 때, 위로 올라가다 처음 오른쪽 위로 꺾였을 때 첫 노드
    x = p;
    p = p->parent;
  }
  return p;
}


// 노드 삭제 시 rbtree 특성 유지시키는 함수
void *delete_fixup(rbtree *t, Node_RB * x) {
  Node_RB *s;  // x노드의 형제 노드
  Node_RB *s_left, * s_right; // s노드의 좌, 우 자식 노드
  while (x != t->root && x->color == RBTREE_BLACK) {
    if (x == x->parent->left) {  // x노드가 왼쪽에 있다면
      s = x->parent->right;
      if (s->color == RBTREE_RED) {  //  case1: 형제 노드가 red일 경우
        s->color = RBTREE_BLACK;
        x->parent->color = RBTREE_RED;
        t->root = left_rotate(t->root, x->parent);
        s = x->parent->right;
      }
      s_left = node_nil(s_left);
      s_right = node_nil(s_right);
      if ((s_left->color == RBTREE_BLACK) && (s_right->color == RBTREE_BLACK)) {  // case2: 형제 노드 'black', 형제 노드의 자식 노드 모두 'black'
        s->color = RBTREE_RED;  // 색상 전환
        x = x->parent;
      }
      else {
        if (s_right->color == RBTREE_BLACK) {  // case3: 형제 노드 'black', 형제 좌노드 'red', 형제 우노드 'black'
          s_left->color = RBTREE_BLACK;
          s->color = RBTREE_RED;
          t->root = right_rotate(t->root, s);  // 단일 회전
          s = x->parent->right;
        }
        s->color = x->parent->color;
        x->parent->color = RBTREE_BLACK;
        s->right->color = RBTREE_BLACK;
        t->root = left_rotate(t->root, x->parent);
        x = t->root;
      }
    }
    else {
      s = x->parent->left;
      if (s->color == RBTREE_RED) { //Original: s->color == RBTREE_RED
        s->color = RBTREE_BLACK;
        x->parent->color = RBTREE_RED;
        t->root = right_rotate(t->root, x->parent);
        s = x->parent->left;
      }
      s_left = node_nil(s_left);
      s_right = node_nil(s_right);
      if ((s_right->color == RBTREE_BLACK) && (s_left->color == RBTREE_BLACK)) {
        s->color = RBTREE_RED;
        x = x->parent;
      }
      else {
        if (s_left->color == RBTREE_BLACK) {
          s_right->color = RBTREE_BLACK;
          s->color = RBTREE_RED;
          t->root = left_rotate(t->root, s);
          s= x->parent->left;
        }
        s->color = x->parent->color;
        x->parent->color = RBTREE_BLACK;
        s->left->color = RBTREE_BLACK;
        t->root = right_rotate(t->root, x->parent);
        x = t->root;
      }
    }
  }
  x->color = RBTREE_BLACK;
}

int rbtree_delete(rbtree *t, Node_RB *p) {
  Node_RB *y = p;  // 삭제되거나 이동될 노드
  Node_RB *x;  // y의 원래 위치(삭제 or 이동되기 전 위치)
  color_t y_or_color = y->color;  // y의 원래 색

  if (p->left == NULL) {  // p노드의 좌노드가 없을 때
    x = node_nil(p->right);
    tree_transplant(t, p, x);
    free(p);
  }
  else if (p->right == NULL) {  // p노드의 우노드가 없을 때
    x = node_nil(p->left);
    tree_transplant(t, p, x);
    free(p);
  }
  else {  // p노드가 자식노드 모두를 가지고 있을 때
    y = successor(t, p);
    y_or_color = y->color;
    x = node_nil(y->right);

    if (y->parent == p) {
      x->parent = y;
    }
    else {
      tree_transplant(t, y, x);
      y->right = p->right;
      y->right->parent = y;
    }
    tree_transplant(t, p, y);
    y->left = p->left;
    y->left->parent = y;
    y->color = p->color;
    free(p);
  }

  if (y_or_color == RBTREE_BLACK) {
    delete_fixup(t, x);
  }

  // 루트가 nil이 될 경우가 발생하기 때문에 nil과 연결 끊기
  if (t->root == nil) {
    t->root = NULL;
  }
  else if (nil->parent != NULL) {
    if (nil->parent->left == nil) {
      nil->parent->left = NULL;
    }
    else {
      nil->parent->right = NULL;
    }
  }
  nil->parent = NULL;

  return 0;
}

void rb_inorder(Node_RB* node, int* result) {
    if (node == NULL) return;
    if (cur_index_rb >= 11) return;

    rb_inorder(node->left, result);

    printf("%d \n", node->data);

    if (node->right != NULL) {
        printf("Right: %d\n", node->right->data);
    }
    if (node->left != NULL) {
        printf("Left: %d\n", node->left->data);
    }


    result[cur_index_rb] = node->data;
    cur_index_rb++;
    rb_inorder(node->right, result);
}

int* rb_get_inorder(Node_RB* node) {
    int* result = (int*)malloc(sizeof(int) * 11);
    for(int i = 0; i < 11; i++) {
        result[i] = 0;
    }
    rb_inorder(node, result);
    return result;
}