
object Main {

  def main(args: Array[String]) {
    val a = Util.readInt
    val v = Util.readIntegers
    val b = v(0)
    val c = v(1)

    val s = Util.readLine
    print(a+b+c)
    println(" " + s)
  }


}

object Util {
  def readInt: Int = Predef.readInt

  def readIntegers: Array[Int] = {
    Predef.readLine
      .trim
      .split("\\s+")
      .map(_.toInt)
  }

  def readLine: String = Predef.readLine
}
