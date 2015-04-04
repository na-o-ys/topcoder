import java.util
import scala.collection.mutable
import scala.annotation.tailrec

object Main {

  var a = new Array[Int](100000)
  var n = 0

  // main
  def run = {
    val sc = new util.Scanner(System.in)
    n = sc.nextInt
    0 until n foreach { i =>
      a(i) = sc.nextInt
    }

    var b = Array.fill(100001)(false)
    var head, end = 0
    var ans = 0
    b(a(head)) = true
    while (head < n) {
      while (end + 1 < n && !b(a(end + 1))) {
        end += 1
        b(a(end)) = true
      }

      ans = ans max (end - head + 1)

      b(a(head)) = false
      head += 1
    }

    println(ans)
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
