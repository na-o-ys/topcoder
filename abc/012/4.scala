import java.util
import scala.collection.mutable
import scala.annotation.tailrec

object Main {

  // main
  def run = {
    val sc = new util.Scanner(System.in)
    val N = sc.nextInt
    val M = sc.nextInt
    
    def dist(i, j, k) = k match {
      min(dist(i, j, k-1), dist(i, k, k-1) + dist(k, j, k-1))
    }
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
