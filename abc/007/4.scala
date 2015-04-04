import java.util
import scala.collection.mutable

object Main {

  def main(args: Array[String]) {
    val sc = new util.Scanner(System.in)
    var a, b = sc.nextLong
    println(ngCount(b) - ngCount(a-1))
  }

  def ngCount(n: Long): Long = {
    var digits = n.toString.map(_ - '0').reverse

    var (_, ok) = ((1L, 1L) /: digits) {
      case ((all, just), d) =>
        var just_ = d match {
          case d if d < 4 => just + all * d
          case d if d < 9 => just + all * (d-1)
          case 9          => just + all * (d-2)
        }
        (8 * all, just_)
    }

    n + 1 - ok
  }
}
