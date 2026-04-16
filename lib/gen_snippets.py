import os
import json

# 設定
LIB_DIR = os.path.expanduser("~/kyopro/lib")
OUTPUT_PATH = os.path.expanduser("~/kyopro/.vscode/kyopro.code-snippets")

def generate():
    snippets = {}
    
    for root, dirs, files in os.walk(LIB_DIR):
        for file in files:
            if not file.endswith(".cpp"): continue
            
            path = os.path.join(root, file)
            name = os.path.splitext(file)[0]
            
            with open(path, "r") as f:
                content = f.read()
                
            # スニペットとして登録
            snippets[name] = {
                "prefix": name,
                "body": content.splitlines(),
                "description": f"Library: {name}"
            }
            
    # 出力先ディレクトリがない場合は作成
    os.makedirs(os.path.dirname(OUTPUT_PATH), exist_ok=True)
    
    with open(OUTPUT_PATH, "w") as f:
        json.dump(snippets, f, indent=4)
    
    print(f"✅ {len(snippets)} 個のスニペットを同期しました: {OUTPUT_PATH}")

if __name__ == "__main__":
    generate()