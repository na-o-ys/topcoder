import java.util
import scala.collection.mutable
import scala.annotation.tailrec

object Main {

  // main
  def run = {
    val sc = new util.Scanner(System.in)
    val n = sc.nextInt

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
