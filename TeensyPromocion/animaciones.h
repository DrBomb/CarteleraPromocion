const bool circulo[16][16][16] = {
  {
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  },
  {
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  },
  {
    {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  },
  {
    {0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  },
  {
    {0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  },
  {
    {0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  },
  {
    {0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  },
  {
    {0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  },
  {
    {0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  },
  {
    {0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  },
  {
    {0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  },
  {
    {0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  },
  {
    {0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  },
  {
    {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  },
  {
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  },
  {
    {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0}
  } 
};
