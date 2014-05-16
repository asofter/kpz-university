using System;
using System.Text;
using System.Linq;
using System.IO;

namespace lab5
{
    class Document
    {
        public string author;
        public string name;
        public int year;
        public string content;
        public int countOfBodySymbols = 0;
        public int countOfBodyWords = 0;

        public void load(string fileName)
        {
            string[] lines = System.IO.File.ReadAllLines(fileName);

            this.author = lines[0];
            this.name = lines[1];
            this.year = Convert.ToInt32(lines[2]);
            this.content = lines[3];

            char[] allSymbols = new char[] { '.', '?', '!', ';', ':', ',' };
            string[] words = this.content.Split(new char[] { '.', '?', '!', ' ', ';', ':', ',' }, StringSplitOptions.RemoveEmptyEntries);
            this.countOfBodyWords = words.Length;

            char[] chars = this.content.ToCharArray();
            this.countOfBodySymbols = 0;
            foreach (char c in chars)
            {
                if (allSymbols.Contains(c))
                {
                    this.countOfBodySymbols++;
                }
            }
        }

    }

}
