SELECT product_id FROM products WHERE low_fats = 'Y'
INTERSECT
SELECT product_id FROM products WHERE recyclable = 'Y';