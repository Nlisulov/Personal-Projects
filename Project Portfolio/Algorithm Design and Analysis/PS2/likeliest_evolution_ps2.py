'''
CSC373 Fall 2022
Assignment 2
University of Toronto Mississauga
'''

# Do NOT add any "import" statements
# Do NOT use Python dictionaries

def likeliest_evolution(num_variants, poss_evolutions, s, t):
  '''
  Pre: num_variants, poss_evolutions, initital variant s, final variant  t
  Post: return the sequence of evolutions that maximize the total probability
		of a successful evolution from variant s to variant t
  '''

  # # Uncommenting the following lines will result in Case 1 passing
  # path = [1,3,4]
  # prob = 0.81
  # return path, prob

  pass # TODO: implement this function



if __name__ == '__main__':

  # some small test cases
  # Case 1
  path, prob = likeliest_evolution( 4, [[1,2,0.95], [2,1,0.95],
                                       [1,3,0.90], [2,4,0.85], [3,4,0.90]], 1, 4 )
  assert prob ==  0.81
  assert path == [1, 3, 4]
