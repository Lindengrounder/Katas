import java.util.*;

public class KataHTML {
    // Упрощенные классы-заглушки для примера
    static class WikiPage {
        String name;
        WikiPage(String name) { this.name = name; }
    }
    
    static class PageData {
        WikiPage wikiPage;
        String content;
        Map<String, Object> attributes = new HashMap<>();
        
        PageData(WikiPage page, String content) {
            this.wikiPage = page;
            this.content = content;
        }
        
        WikiPage getWikiPage() { return wikiPage; }
        boolean hasAttribute(String key) { return attributes.containsKey(key); }
        String getContent() { return content; }
        void setContent(String content) { this.content = content; }
        String getHtml() { return content; }
    }
    
    static class PageCrawlerImpl {
        static WikiPage getInheritedPage(String pageName, WikiPage wikiPage) {
            // Заглушка - в реальности здесь поиск унаследованной страницы
            if (pageName.equals("SuiteSetup") || pageName.equals("SetUp") || 
                pageName.equals("TearDown") || pageName.equals("SuiteTeardown")) {
                return new WikiPage(pageName);
            }
            return null;
        }
    }
    
    public static String testableHtml(PageData pageData, boolean includeSuiteSetup) throws Exception {
        WikiPage wikiPage = pageData.getWikiPage();
        StringBuffer buffer = new StringBuffer();
        
        if (pageData.hasAttribute("Test")) {
            if (includeSuiteSetup) {
                WikiPage suiteSetup = PageCrawlerImpl.getInheritedPage("SuiteSetup", wikiPage);
                if (suiteSetup != null) {
                    buffer.append("Suite Setup: ").append(suiteSetup.name).append("\n");
                }
            }
            
            WikiPage setUp = PageCrawlerImpl.getInheritedPage("SetUp", wikiPage);
            if (setUp != null) {
                buffer.append("SetUp: ").append(setUp.name).append("\n");
            }
        }
        
        buffer.append(pageData.getContent()).append("\n");
        
        if (pageData.hasAttribute("Test")) {
            WikiPage tearDown = PageCrawlerImpl.getInheritedPage("TearDown", wikiPage);
            if (tearDown != null) {
                buffer.append("TearDown: ").append(tearDown.name).append("\n");
            }
            
            if (includeSuiteSetup) {
                WikiPage suiteTearDown = PageCrawlerImpl.getInheritedPage("SuiteTeardown", wikiPage);
                if (suiteTearDown != null) {
                    buffer.append("Suite Teardown: ").append(suiteTearDown.name).append("\n");
                }
            }
        }
        
        pageData.setContent(buffer.toString());
        return pageData.getHtml();
    }
    
    public static void main(String[] args) {
        try {
            // Тестовый пример
            WikiPage testPage = new WikiPage("TestPage");
            PageData pageData = new PageData(testPage, "Основной контент теста");
            pageData.attributes.put("Test", true);
            
            System.out.println("=== Без SuiteSetup ===");
            String result1 = testableHtml(pageData, false);
            System.out.println(result1);
            
            System.out.println("\n=== С SuiteSetup ===");
            String result2 = testableHtml(pageData, true);
            System.out.println(result2);
            
            // Тест без атрибута "Test"
            PageData nonTestPage = new PageData(testPage, "Обычная страница");
            System.out.println("\n=== Не тестовая страница ===");
            String result3 = testableHtml(nonTestPage, true);
            System.out.println(result3);
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
