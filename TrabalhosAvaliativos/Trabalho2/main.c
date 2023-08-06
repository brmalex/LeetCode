int fillCups(int* amount, int amountSize){
    int r = 0;
    if ((amount[0]) > (amount[1]+amount[2])){
      r = amount[0]-(amount[1]+amount[2]);
    }
    else if ((amount[1]) > (amount[0]+amount[2])){
      r = amount[1]-(amount[0]+amount[2]);
    }
    else if ((amount[2]) > (amount[0]+amount[1])){
      r = amount[2]-(amount[1]+amount[0]);
    }
    else {
      r = (amount[0]+amount[1]+amount[2])%2;
    }
    r = r+((amount[0]+amount[1]+amount[2]-r)/2);
    return r;
}
