SELECT * FROM vehicles v
LEFT JOIN semi_trailers st ON v.id = st.id
LEFT JOIN reefers r ON v.id = r.trailer_id