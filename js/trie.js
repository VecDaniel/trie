function TrieNode(char, leaf)
{
    if (char === undefined)
        char = '';
    if (leaf === undefined)
        leaf = false;
    this.char = char;
    this.leaf = leaf;
    this.desc = []; // array
    
    this.add = function(string)
    {
        var firstChar = string[0];
        
        l = this.desc.length;
        for (i=0;i<l;i++)
        {
            if (this.desc[i].char==firstChar)
            {
                if (string.length == 1)
                    this.desc[i].leaf = true;
                else
                    this.desc[i].add(string.substr(1));
                return;
            }
        }
        
        var newNode = new TrieNode(firstChar,string.length == 1 ? true : false);
        if (string.length > 1)
            newNode.add(string.substr(1));
        this.desc.push(newNode);
    }
    
    this.print = function(string)
    {
        var ret="";
        if (string === undefined)
            string = "";
        var current = string + this.char;
        if (this.leaf == true)
            ret = ret + current + "\n";
        var l = this.desc.length;
        var i;
        for (i=0;i<l;i++)
        {
            ret = ret + this.desc[i].print(current);
        }
        return ret;
    }
}

trie = new TrieNode();
trie.add("car");
trie.add("carte");
trie.add("carnaval");
trie.add("pisica");
alert(trie.print());