// To see the comments (ctrl+f replace all false -> 0 and true -> 1
static const short FIGURE_SIZE = 72;
bool FIGURE[FIGURE_SIZE][8] = {   
  {true, false, false, false, false, false, false, false}, // false
  {false, true, true, false, false, false, false, false},
  {false, false, true, true, true, false, false, false},
  {false, false, false, false, false, true, true, true},
  {false, false, false, false, false, false, true, true},
  {false, false, false, false, false, true, true, false}, // 5
  {false, false, false, false, true, true, false, false},
  {false, false, false, true, true, false, false, false},
  {false, false, true, true, false, false, false, false},
  {false, false, true, false, false, false, false, false},
  {false, false, true, false, false, false, false, false}, // truefalse
  {false, false, true, false, false, false, false, false},
  {false, false, true, false, false, false, false, false},
  {false, false, true, false, false, false, false, false},
  {false, false, true, false, false, false, false, false},
  {false, false, true, false, false, false, false, false}, // true5
  {false, false, false, true, false, false, false, false},
  {false, false, false, true, true, false, false, false},
  {false, false, false, false, true, true, false, false},
  {false, false, false, false, false, true, true, false},
  {false, false, false, false, false, false, false, true}, // 2false
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false}, // 25
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false}, // 3false
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false}, // 35
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false}, // 4false
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false}, // 45
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false}, // 5false
  {false, false, false, false, false, false, false, true},
  {false, false, false, false, false, true, true, false},
  {false, false, false, false, true, true, false, false},
  {false, false, false, true, true, false, false, false},
  {false, false, false, true, false, false, false, false}, // 55
  {false, false, true, false, false, false, false, false},
  {false, false, true, false, false, false, false, false},
  {false, false, true, false, false, false, false, false},
  {false, false, true, false, false, false, false, false},
  {false, false, true, false, false, false, false, false}, // 6false
  {false, false, true, false, false, false, false, false},
  {false, false, true, false, false, false, false, false},
  {false, false, true, true, false, false, false, false},
  {false, false, false, true, true, false, false, false},
  {false, false, false, false, true, true, false, false}, // 65
  {false, false, false, false, false, true, true, false},
  {false, false, false, false, false, false, true, true},
  {false, false, false, false, false, true, true, true},
  {false, false, true, true, true, false, false, false},
  {false, true, true, false, false, false, false, false}, // 7false
  {true, false, false, false, false, false, false, false} 
};


