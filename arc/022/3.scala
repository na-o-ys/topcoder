import java.util
import scala.collection.mutable
import scala.annotation.tailrec

object Main {

  var graph:Array[List[Int]] = Array.fill(100010)(List())

  // main
  def run = {
    val sc = new util.Scanner(System.in)
    val n = sc.nextInt
    0 until n-1 foreach { _ =>
      val a, b = sc.nextInt - 1
      this.graph(a) = b :: this.graph(a)
      this.graph(b) = a :: this.graph(b)
    }

    var s = getFarthestNode(0)
    var t = getFarthestNode(s)

    printf("%d %d", s+1, t+1)
    println
  }

  def getFarthestNode(root: Int): Int = {
    @tailrec
    def bfs(nodeList: List[(Int, Int)]): List[(Int, Int)] = {
      nodeList.flatMap {
        case (p, c) => this.graph(c) filter(_ != p) map((c, _))
      } match {
        case Seq() => nodeList
        case l     => bfs(l)
      }
    }

    bfs(List((-1, root))).head._2
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
