def dijkstra(graph, a, b)

end

if $0 == __FILE__ then
  while true do 
    n, e = gets.strip.split(' ').map(&:to_i)
    break if n==0 and e==0
    graph = Array.new(n+1) { Array.new(n+1, 0) }
    e.times do 
      a, b, w = gets.strip.split(' ').map(&:to_i)
      graph[a][b] = w
    end

    gets.to_i.times do
      a, b = gets.strip.split(' ').map(&:to_i)
      min_t = dijkstra(graph, a, b)
      if min_t then
        puts(min_t)
      else
        puts("Nao e possivel entregar a carta")
      end
    end
  end
end
  