import scala.collection.mutable

object Main {

  var graph:Array[List[Int]] = Array.fill(100010)(List())

  // main
  def run = {
    val n = readInt
    for (i <- 0 until n-1) {
      val v = readLine.split(" ").map(_.toInt)
      v(0) -= 1; v(1) -= 1;
      this.graph(v(0)) = v(1) :: this.graph(v(0))
      this.graph(v(1)) = v(0) :: this.graph(v(1))
    }

    var s = getFarthestNode(-1, 0)
    var t = getFarthestNode(-1, s)

    printf("%d %d", s+1, t+1)
    println
  }

  def getFarthestNode(parent: Int, curr: Int): Int = {
    def bfs(nodeList: List[(Int, Int)]): List[(Int, Int)] = {
      nodeList.flatMap { p =>
        this.graph(p._2) filter(_ != p._1) map((p._2, _))
      } match {
        case Seq() => nodeList
        case l     => bfs(l)
      }
    }

    bfs(List((parent, curr)), 0)(0)._2
  }

  def dfsByRec(parent: Int, curr: Int): (Int, Int) = {
    this.graph(curr)
      .foldLeft(curr, 0)((z, n) => n match {
        case `parent` => z
        case _        => getFarthestNode(curr, n) match {
          case (node, dist) if dist+1 > z._2 => (node, dist+1)
          case _                             => z
        }
      })
  }

  def dfsByStack(parent: Int, curr: Int): (Int, Int) = {
    var stack = new mutable.ArrayStack[(Int, Int, Int)]
    stack.push(curr, -1, 0)

    var dist = 0
    var node = curr
    while(!stack.isEmpty) {
      var (c, p, d) = stack.pop

      if (dist < d) {
        dist = d
        node = c
      }

      this.graph(c).foreach { n =>
        if (n != p) stack.push(n, c, d + 1)
      }
    }

    (node, dist)
  }

  def bfs(parent: Int, curr: Int): (Int, Int) = {
    var q = new mutable.Queue[(Int, Int, Int)]
    q += ((curr, -1, 0))

    var depth = 0
    var node = curr
    while (!q.isEmpty) {
      var (c, p, d) = q.dequeue

      if (depth < d) {
        depth = d
        node = c
      }

      this.graph(c).foreach { n =>
        if (n != p) {
          q += ((n, c, d+1))
        }
      }
    }

    (node, depth)
  }

  def main(args: Array[String]) {
    // to avoid stack overflow
    new Thread(
      null,
      new Runnable { override def run = Main.run },
      "1",
      1 << 28).start
  }
}
