# URI-1973: Star Trek 

n = gets.to_i()
x = gets.split(" ").map(&:to_i)

visited = Array.new(n, false)
initial_sheeps = x.sum()

indx = 0
stolen_sheeps = 0

while indx>=0 and indx<n do 
    visited[indx] = true 
    curr_indx = indx
    indx += x[indx].even? ? -1 : 1
    if x[curr_indx]>0 then
        x[curr_indx] -= 1
        stolen_sheeps += 1
    end
end

puts("#{visited.count(true)} #{initial_sheeps - stolen_sheeps}")
