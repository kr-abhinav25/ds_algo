#  https://leetcode.com/problems/number-of-islands/description/

def searchNeighbours(grid, gridLength, rowLength, row_index, item_index)
  grid[row_index][item_index] = "0"

  # check up neighbour
  i = row_index - 1
  j = item_index
  if i >= 0 and j>= 0 and i < gridLength and j < rowLength and grid[i][j] == "1"
    searchNeighbours(grid,gridLength, rowLength, i, j)
  end

  # check right neighbour
  i = row_index
  j = item_index + 1
  if i >= 0 and j>= 0 and i < gridLength and j < rowLength and grid[i][j] == "1"
    searchNeighbours(grid, gridLength, rowLength, i, j)
  end  

  # check down neighbour
  i = row_index + 1
  j = item_index
  if i >= 0 and j>= 0 and i < gridLength and j < rowLength and grid[i][j] == "1"
    searchNeighbours(grid, gridLength, rowLength, i, j)
  end

  # check left neighbour
  i = row_index
  j = item_index - 1
  if i >= 0 and j>= 0 and i < gridLength and j < rowLength and grid[i][j] == "1"
    searchNeighbours(grid, gridLength, rowLength, i, j)
  end  
end

def num_islands(grid)
  islandCount = 0;
  gridLength = grid.length
  rowLength = grid[0].length
  grid.each_with_index do |row, row_index|
    row.each_with_index do |item, item_index|
      if item == "1"
        searchNeighbours(grid, gridLength, rowLength, row_index, item_index)
        islandCount += 1;
      end
    end
  end
  islandCount
end

grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]

result = num_islands(grid)
puts result